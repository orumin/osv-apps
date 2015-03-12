.PHONY: module clean
module: ROOTFS usr.manifest

ROOTFS:
	mkdir -p ROOTFS/sokuten/bin

ROOTFS/sokuten/bin/sokuten: ROOTFS
	cd ROOTFS/sokuten/ && echo "source 'https://rubygems.org'" >> Gemfile
	cd ROOTFS/sokuten/ && echo "gem 'curses','1.0.1'" >> Gemfile
	cd ROOTFS/sokuten/ && echo "gem 'sokuten'" >> Gemfile
	cd ROOTFS/sokuten/ && bundle install --standalone
	cp ROOTFS/sokuten/bundle/ruby/2.2.0/gems/sokuten-0.1.1/bin/sokuten ROOTFS/sokuten/bin/

usr.manifest: ROOTFS/sokuten/bin/sokuten
	echo '/sokuten/**: $${MODULE_DIR}/ROOTFS/sokuten/**' >> usr.manifest
	find ROOTFS/sokuten/bundle/** -name '*.so' -exec ldd {} \;|awk '{print $$1,":",$$3}'|grep "/lib64"|grep -v "ld-linux"|grep -v "libc.so"|grep -v "libpthread.so"|grep -v "libdl.so"|grep -v "libm.so"|grep -v "libstdc++"|grep -v "libgcc_s"|grep -v "librt"|grep -v "sqlite3"|grep -v "libssl.so"|sort|uniq|sed -e "s/ //" \
		>> usr.manifest

clean:
	rm -rf usr.manifest ROOTFS
