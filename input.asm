mvi b, 00h
lxi hl, 2010h
mvi c, 05h

loop: jz final

add b, m
inx h
dcr c

jmp loop

final: hlt
