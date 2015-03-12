from osv.modules import api

api.require('ruby')
default = api.run(cmdline="--cwd=/sokuten/ --env=GEM_HOME=/sokuten/bundle/ruby/2.2.0/ /ruby.so ./bin/sokuten")
