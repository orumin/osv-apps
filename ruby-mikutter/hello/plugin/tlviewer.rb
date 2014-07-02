Plugin.create(:tlviewer) do
  on_update do |s, ms|
    ms.each do |m|
      puts "#{m[:user][:screen_name]}: #{m[:message]}"
    end
  end
end
