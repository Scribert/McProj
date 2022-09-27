import minecraft_editor as mc

myElement = mc.Element("robot")
#bob = mc.ElementAttr()

def keyPressed(key):
    if key == mc.KEY_SPACE:
        print("SPACE IS WACK!")
    print(myElement)
    myElement.attributes["whelp"] = "20"
    myElement.attributes["whelpp"] = "70"
    myElement.attributes["whelppp"] = "180"
    for att in myElement.attributes:
        print(att)
    myElement.attributes = {'LITTLE': "MACK", "PIZZA": (5, 6)}
    #myElement.addChild(mc.Element("Fire bacon"))
    print(myElement.contents)
    
def mouseButtonPressed():
    print("HIEDIDOOOOOO")