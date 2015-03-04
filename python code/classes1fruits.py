class fruits(object):
    def __init__(selfa,name,colour,flavour,poisoness):
        selfa.name = name
        selfa.colour = colour
        selfa.flavour = flavour
        selfa.poisoness = poisoness
    def description(selfa):
        print "I am %s %s coloured %s in taste" %(selfa.name,selfa.colour,selfa.flavour)
    def is_edible(selfa):
        if "Ture" == selfa.poisoness: 
            print "I am not edible"
        else:
            print "I'm edible, You can eat me"
apple = fruits("apple","red","sweet","False")
apple.description()
apple.is_edible()
lemon = fruits("lemon","yellow","sour","True")
lemon.description()
lemon.is_edible()
