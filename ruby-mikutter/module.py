from osv.modules import api

default = api.run(cmdline="--cwd=/mikutter/ --env=GEM_HOME=/mikutter/vendor/bundle/ruby /ruby.so /mikutter/mikutter.rb --confroot=/mikutter/hello")
