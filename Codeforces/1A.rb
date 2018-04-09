buf = gets.split(' ').map(&:to_i)
n, m, a = buf[0], buf[1], buf[2]

if n % a == 0 && m % a == 0
  puts (n / a) * (m / a)
elsif n % a == 0
  puts (n / a) * (m / a + 1)
elsif m % a == 0
  puts (n / a + 1) * (m / a)
else
  puts (n / a + 1) * (m / a + 1)
end
