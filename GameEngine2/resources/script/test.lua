local Vector2 = require("stamp.Vector2")
print("Hello World!")

local v1 = Vector2:new(2)
local v2 = Vector2:new(9,10)

print(instance(v1))

print(v1 + v2)

