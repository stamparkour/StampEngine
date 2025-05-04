print("hello world")

print(Engine.DeltaTime())
myEntity = EntityBase:register("test:my_entity")
local k = myEntity.mass
myEntity.mass = 12
print(myEntity.mass)