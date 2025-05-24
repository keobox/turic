_aS = 8  ; size = 4
_bS = 12 ; sice = 4

_sum PROC
     push ebp
     mov  ebp, esp
     mov  eax, DWORD PTR _aS[ebp]
     add  eax, DWORD PTR _bS[ebp]
     pop  ebp
     ret  0
_sum ENDP

_main PROC
      push ebp
      mov  ebp, esp
      push  20 ; 00000014H
      push  10 ; 0000000aH
      call _sum
      add  esp, 8
      pop  ebp
      ret  0
_main ENDP
