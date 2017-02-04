push int8(127) ;good
push int8(-128) ;good
;push int8(128) ;overflow
;push int8(-129) ;overflow
push int16(32767) ;good
push int16(-32768) ;good
;push int16(32768) ;overflow
;push int16(-32769) ;overflow
push int32(2147483647) ;good
push int32(-2147483648) ;good
;push int32(2147483648) ;overflow
;push int32(-2147483649) ;overflow

dump
exit

;limit.asm: line 3: bad numeric conversion: positive overflow
;limit.asm: line 4: bad numeric conversion: negative overflow
;limit.asm: line 7: bad numeric conversion: positive overflow
;limit.asm: line 8: bad numeric conversion: negative overflow
;limit.asm: line 11: bad numeric conversion: positive overflow
;limit.asm: line 12: bad numeric conversion: negative overflow
