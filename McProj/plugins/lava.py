import minecraft_editor as mc

def mouseButtonPressed(button, modifier):
    if modifier == mc.MOD_CONTROL | mc.MOD_ALT:
        print("ctrl alt click")
def keyReleased(button):
    print(button, "yp")