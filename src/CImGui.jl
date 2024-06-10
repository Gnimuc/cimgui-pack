module CImGui

using LibCImGui

using CSyntax
using CEnum
using CEnum: Cenum, name_value_pairs

const IM_COL32_R_SHIFT = 0
const IM_COL32_G_SHIFT = 8
const IM_COL32_B_SHIFT = 16
const IM_COL32_A_SHIFT = 24
const IM_COL32_A_MASK  = 0xff000000
IM_COL32(R,G,B,A) = (ImU32(A)<<IM_COL32_A_SHIFT) | (ImU32(B)<<IM_COL32_B_SHIFT) | (ImU32(G)<<IM_COL32_G_SHIFT) | (ImU32(R)<<IM_COL32_R_SHIFT)

const IM_COL32_WHITE       = IM_COL32(255,255,255,255)  # opaque white = 0xffffffff
const IM_COL32_BLACK       = IM_COL32(0,0,0,255)        # opaque black
const IM_COL32_BLACK_TRANS = IM_COL32(0,0,0,0)          # transparent black = 0x00000000
const IMGUI_PAYLOAD_TYPE_COLOR_3F = "_COL3F"
const IMGUI_PAYLOAD_TYPE_COLOR_4F = "_COL4F"
const FLT_MAX = igGET_FLT_MAX()
const FLT_MIN = igGET_FLT_MIN()

Base.convert(::Type{ImVec2}, x::NTuple{2}) = ImVec2(x...)
Base.convert(::Type{ImVec2}, x::Vector) = ImVec2(x...)
Base.convert(::Type{ImVec4}, x::NTuple{4}) = ImVec4(x...)
Base.convert(::Type{ImVec4}, x::Vector) = ImVec4(x...)
Base.convert(::Type{ImVec4}, x::ImU32) = ColorConvertU32ToFloat4(x)
Base.convert(::Type{ImU32}, x::ImVec4) = ColorConvertFloat4ToU32(x)

Base.:~(x::Cenum{UInt32}) = ~UInt32(x)
Base.:(:)(a::T, b::Cenum) where {T<:Integer} = a:T(b)
Base.:(:)(a::Cenum, b::T) where {T<:Integer} = T(a):b

function ShowFlags(::Type{T}) where {T<:Cenum}
    io = IOBuffer()
    s = "```\n"
    for (n,v) in name_value_pairs(T)
        s *= string(n)*" $v \n"
    end
    s*"\n```"
end
GetFlags(::Type{T}) where {T<:Cenum} = name_value_pairs(T) |> collect

function c_get(x::Ptr{NTuple{N,T}}, i) where {N,T}
    unsafe_load(Ptr{T}(x), Integer(i)+1)
end

function c_set!(x::Ptr{NTuple{N,T}}, i, v) where {N,T}
    unsafe_store!(Ptr{T}(x), v, Integer(i)+1)
end

include("wrapper.jl")

const IMGUI_VERSION = unsafe_string(GetVersion())

## Backends

# These are backend functions that must be implemented by a package extension
# for a backend.
function _render end
function _create_image_texture end
function _update_image_texture end
function _destroy_image_texture end

"""
    backend::Symbol

Specifies the backend to use. Currently supported backends are:
- `:GlfwOpenGL` (GLFW/OpenGL3)
"""
backend = nothing

function _check_backend()
    if isnothing(backend)
        error("You must set `CImGui.backend` to the backend you want before calling this function, e.g. `CImGui.backend = :GlfwOpenGL` for the GLFW/OpenGL3 backend.")
    end
end

function render(args...; kwargs...)
    _check_backend()
    _render(args..., Val(backend); kwargs...)
end

function create_image_texture(args...; kwargs...)
    _check_backend()
    _create_image_texture(Val(backend), args...; kwargs...)
end

function update_image_texture(args...; kwargs...)
    _check_backend()
    _update_image_texture(Val(backend), args...; kwargs...)
end

function destroy_image_texture(args...; kwargs...)
    _check_backend()
    _destroy_image_texture(Val(backend), args...; kwargs...)
end

function __init__()
    Base.Experimental.register_error_hint(MethodError) do io, exc, argtypes, kwargs
        if exc.f === render
            if isempty(methods(exc.f))
                print(io, "\nrender()has no methods yet. You must load the packages for supported backends, e.g. `import ModernGL, GLFW` for the GLFW/OpenGL3 backend.")
            end
        end
    end
end

end # module
