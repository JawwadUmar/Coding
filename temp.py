class persons:

    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def introduce(self):
        print(f"Hello my name is {self.name} and my age is {self.age}")


person1 = persons("Alice", 25)

person1.introduce()
