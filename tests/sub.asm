push int32(1)
push int32(3)
sub
assert int32(2)
pop

push int8(1)
push int32(100000)
sub
assert int32(99999)
pop

push float(0.14)
push int16(3)
sub
assert double(2.86)
pop

exit
