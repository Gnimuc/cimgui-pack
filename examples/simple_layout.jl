using CImGui

let selected = 1
"""
    show_app_layout(p_open::Ref{Bool})
Create a window with multiple child windows.
"""
global function show_app_layout(p_open::Ref{Bool})
    CImGui.SetNextWindowSize((500, 440), CImGui.ImGuiCond_FirstUseEver)
    if CImGui.Begin("Example: Layout", p_open, CImGui.ImGuiWindowFlags_MenuBar)
        if CImGui.BeginMenuBar()
            if CImGui.BeginMenu("File")
                CImGui.MenuItem("Close") && (p_open[] = false;)
                CImGui.EndMenu()
            end
            CImGui.EndMenuBar()
        end

        # left
        CImGui.BeginChild("left pane", (150, 0), true)
        for i = 1:100
            CImGui.Selectable("MyObject $i", selected == i) && (selected = i;)
        end
        CImGui.EndChild()
        CImGui.SameLine()

        # right
        CImGui.BeginGroup()
            # leave room for 1 line below us
            CImGui.BeginChild("item view", (0.0f0, -CImGui.GetFrameHeightWithSpacing()))
                CImGui.Text("MyObject: $selected")
                CImGui.Separator()
                CImGui.TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
            CImGui.EndChild()
            if CImGui.Button("Revert")
                @info "Trigger Revert | find me here: $(@__FILE__) at line $(@__LINE__)"
            end
            CImGui.SameLine()
            if CImGui.Button("Save")
                @info "Trigger Save | find me here: $(@__FILE__) at line $(@__LINE__)"
            end
        CImGui.EndGroup()
    end
    CImGui.End()
end

end # let
