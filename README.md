
6.12 Build CPU Initially

```bash
chmod +x run.sh
./run.sh
lldb ./main_6502
```

```
(lldb) target create "./main_6502"
Current executable set to '/Users/cherongtian/Desktop/CPU/main_6502' (arm64).
(lldb) b 110
Breakpoint 1: where = main_6502`main + 124 at main_6502.cpp:110:5, address = 0x0000000100000514
(lldb) r
Process 58354 launched: '/Users/cherongtian/Desktop/CPU/main_6502' (arm64)
Process 58354 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
    frame #0: 0x0000000100000514 main_6502`main at main_6502.cpp:110:5
   107      // end-inline a little program
   108      cpu.Execute(2, mem);
   109      
-> 110      return 0;
   111  }
Target 0: (main_6502) stopped.
(lldb) p cpu.A
(Byte) 'B'
(lldb) p cpu.PC
(Word) 65534
(lldb) p cpu.Z
(Byte:1) '\0'
(lldb) q
Quitting LLDB will kill one or more processes. Do you really want to proceed: [Y/n] y
```