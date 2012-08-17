class SwissWatch
  # this little method uses the magic __FILE__ value to generate a path
  # relative to this file
  def self.location
    File.expand_path(
      File.join(
        File.dirname(__FILE__),
        ".")) # <-- change this appropriately if this file not at project root
  end
end