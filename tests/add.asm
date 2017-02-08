push int32(1)
push int32(3)
add
assert int32(4)
pop

push int8(1)
push int32(100000)
add
assert int32(100001)
pop

push int16(3)
push float(0.14)
add
assert double(3.14)
pop

exit
