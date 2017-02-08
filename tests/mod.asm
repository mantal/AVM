push int32(2)
push int32(3)
mod
assert int32(1)
pop

push int8(5)
push int32(10)
mod
assert int32(0)
pop

push int16(3)
push int8(1)
mod
assert int32(1)
pop

exit
