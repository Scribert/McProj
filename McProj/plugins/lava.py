import minecraft_editor as mc

def mouseButtonPressed(button, modifier):
    j = mc.Component.get("root")
    j.addSub("roots", mc.Component.Type.Scene, 0)
    print(mc.Component.get("root").sub(0).name)
    if modifier == mc.MOD_CONTROL | mc.MOD_ALT:
        print("ctrl alt click")
def keyReleased(button):
    print(button, "yp")