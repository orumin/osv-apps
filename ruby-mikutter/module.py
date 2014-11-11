from osv.modules import api

api.require('ruby')
default = api.run(cmdline="--cwd=/mikutter/ --env=HOME=/ --env=GEM_HOME=/mikutter/vendor/bundle/ruby/2.1.0 /ruby.so /mikutter/mikutter.rb --confroot=/mikutter/hello")
