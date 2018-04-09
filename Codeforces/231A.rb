n = gets.to_i
count = 0
for i in 1..n
  buf = gets.split(' ').map(&:to_i)
  a, b, c = buf[0], buf[1], buf[2]
  count += 1 if a + b + c >= 2
end
puts count
