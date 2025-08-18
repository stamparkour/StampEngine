print("hello world")

print(Engine.DeltaTime())
myEntity = EntityBase:register("test:my_entity")
local k = myEntity.mass
myEntity.mass = 12
print(myEntity.mass)

Engine.BindAction(10, {
	key=1, --left mouse
})

Engine.BindAction(1, {
	key=87, --W key
	ignoreMod = true, alt = false, shift = false, control = false
})

