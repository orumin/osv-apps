.PHONY: module
module: osv/osv.so

osv/Makefile:
	cd osv && ruby extconf.rb
osv/osv.so: osv/Makefile
	cd osv && make
