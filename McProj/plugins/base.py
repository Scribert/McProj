import minecraft_editor as mc
def mouseMoved(vector):
    print(vector.x, vector.y)
    e = mc.vec3(0.0, 4.0, 3.0)
def keyPressed(key):
    if key == mc.KEY_SPACE:
        print("SPACE IS WACK!")
def mouseButtonPressed():
    print("HIEDIDOOOOOO")