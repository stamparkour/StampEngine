local Vector2 = stamp.math.Vector2
print("Hello World!")
print(Vector2.__type.name)

local v1 = Vector2:new(2)
local v2 = Vector2:new(10,10)

print(instanceof(v1, Vector2))

print(stamp.math.cross(v1, v2))

