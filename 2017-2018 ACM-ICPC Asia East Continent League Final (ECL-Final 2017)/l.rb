t = gets.to_i
for tt in 1..t
  n = gets.to_i
  print "Case ##{tt}: "
  if n < 7
    puts "Draw"
  elsif n % 2 == 1
    puts "Panda"
  elsif n >= 16
    puts "Sheep"
  else
    puts "Draw"
  end
end
