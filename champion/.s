.name "Dave"
.comment "Tu connais Mathieu ?"


ld %1,r2
ld %57672451, r3
ld %511, r4
ld %510, r5
sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup:
	sti r1, %:live, %1
fork:
	fork %470
live:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup2:
	sti r1, %:live2, %1
fork2:
	fork %470
live2:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup3:
	sti r1, %:live3, %1
fork3:
	fork %470
live3:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup4:
	sti r1, %:live4, %1
fork4:
	fork %470
live4:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup5:
	sti r1, %:live5, %1
fork5:
	fork %470
live5:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup6:
	sti r1, %:live6, %1
fork6:
	fork %470
live6:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup7:
	sti r1, %:live7, %1
fork7:
	fork %470
live7:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup8:
	sti r1, %:live8, %1
fork8:
	fork %470
live8:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup9:
	sti r1, %:live9, %1
fork9:
	fork %470
live9:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup10:
	sti r1, %:live10, %1
fork10:
	fork %470
live10:
	live %1

sti r3, r4, r6
sti r2, r4, r6
sti r1, r5, r6
backup11:
	sti r1, %:live11, %1
fork11:
	fork %470
live11:
	live %1
add r4, r5, r4
and	r1,%0,r1
zjmp %:live

