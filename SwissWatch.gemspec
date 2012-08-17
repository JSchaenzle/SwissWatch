require File.expand_path("../lib/newgem/version", __FILE__)

Gem::Specification.new do |s|
  s.name        = "swisswatch"
  s.version     = NewGem::VERSION
  s.platform    = Gem::Platform::RUBY
  s.authors     = ["Jordan Schaenzle"]
  s.email       = ["jschaenzle@gmail.com"]
  s.homepage    = "http://github.com/JSchaenzle/SwissWatch"
  s.summary     = "A priority based task scheduler for C programs."
  s.description = "A priority based task scheduler for C programs."

  s.required_rubygems_version = ">= 1.3.6"

  # lol - required for validation
  #s.rubyforge_project         = "newgem"

  # If you have other dependencies, add them here
  # s.add_dependency "another", "~> 1.2"

  # If you need to check in files that aren't .rb files, add them here
  #s.files        = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
  s.files        = Dir["*"]
  s.require_path = '.'

  # If you need an executable, add it here
  # s.executables = ["newgem"]

  # If you have C extensions, uncomment this line
  # s.extensions = "ext/extconf.rb"
end