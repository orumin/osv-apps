require "osv"

puts "test.rb start"
ret = OSv.run_namespace("/ruby.so", ["-rtracer", "-d", "child.rb"])
puts "test.rb ret:#{ret}"
