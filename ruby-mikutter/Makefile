.PHONY: module
module: ROOTFS usr.manifest

ROOTFS/mikutter.3.1.0-alpha4.tar.gz:
	mkdir -p ROOTFS
	cd ROOTFS && wget http://mikutter.hachune.net/bin/mikutter.3.1.0-alpha4.tar.gz
	cd ROOTFS && tar xvf mikutter.3.1.0-alpha4.tar.gz
	cd ROOTFS/mikutter && patch -p1 < ../../mikutter.patch

tmp/bin/bundle: 
	GEM_HOME=tmp gem install --no-ri --no-rdoc bundler

ROOTFS/mikutter/vendor/bundle: tmp/bin/bundle ROOTFS/mikutter.3.1.0-alpha4.tar.gz
	cd ROOTFS/mikutter && env GEM_HOME=../../tmp/bin ../../tmp/bin/bundle install --path vendor/bundle
	cp -r hello ROOTFS/mikutter/
ROOTFS: ROOTFS/mikutter/vendor/bundle

usr.manifest:
	echo '/mikutter/**: $${MODULE_DIR}/ROOTFS/mikutter/**' >> usr.manifest
	echo '/.mikutter/**: $${MODULE_DIR}/.mikutter/**' >> usr.manifest
	find ROOTFS/mikutter/vendor/bundle -name '*.so' -exec ldd {} \;|awk '{print $$1,":",$$3}'|grep "/lib"|grep -v "ld-linux"|grep -v "libc.so"|grep -v "libpthread.so"|grep -v "libdl.so"|grep -v "libm.so"|grep -v "libstdc++"|grep -v "libgcc_s"|grep -v "librt"|sort|uniq|sed -e "s/ //" \
		>> usr.manifest
	
clean:
	rm -rf usr.manifest ROOTFS tmp
