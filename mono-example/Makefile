.PHONY: module
module: usr.manifest

CFLAGS=-std=gnu99 -fpie -rdynamic `pkg-config --cflags mono-2`
LDFLAGS=-pie `pkg-config --libs mono-2`

ROOTFS/run_mono: run_mono.c
	mkdir -p ROOTFS
	pkg-config --exists mono-2 || echo "Please install mono2. For details read https://www.mono-project.com/download/stable/#download-lin"
	$(CC) -o $@ $(CFLAGS) run_mono.c $(LDFLAGS)

ROOTFS/hello.exe: hello.cs
	mkdir -p ROOTFS
	csc hello.cs /out:ROOTFS/hello.exe

usr.manifest: ROOTFS/run_mono ROOTFS/hello.exe
	echo '/**: $${MODULE_DIR}/ROOTFS/**' > usr.manifest
	echo "/usr/lib/mono/4.5/mscorlib.dll: /usr/lib/mono/4.5/mscorlib.dll" >> usr.manifest
	echo "/libmonosgen-2.0.so.1: `ldd ROOTFS/run_mono | grep -o "/.*libmonosgen-2.0.so.1"`" >> usr.manifest

clean:
	rm -rf ROOTFS usr.manifest
