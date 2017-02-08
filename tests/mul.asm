push int32(6)
push int32(7)
mul
assert int32(42)
pop

push int8(2)
push int32(100000)
mul
assert int32(200000)
pop

push int16(3)
push float(1.50)
mul
assert double(4.5)
pop

exit
