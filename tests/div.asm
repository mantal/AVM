push int32(7)
push int32(42)
div
assert int32(6)
pop

push int8(2)
push int32(100000)
div
assert int32(50000)
pop

push int16(2)
push float(3.14)
div
assert double(1.57)
pop

exit
