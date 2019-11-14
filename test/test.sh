################### Build test file ###################

####################### Run test ######################

# -Wall -Wextra -Werror -g3 -fsanitize=address
# FLAGS='-Wall -Wextra -Werror -g3 -fsanitize=address'
FLAGS='-Wall -Wextra -Werror -g'

mkdir tmp

# Run test with minimal buffer
gcc ${FLAGS} -D BUFFER_SIZE=1 -I .. ../get_next_line.c ../get_next_line_utils.c test.c -o tmp/test_1

# Run test with middle buffer
gcc ${FLAGS} -D BUFFER_SIZE=32 -I .. ../get_next_line.c ../get_next_line_utils.c test.c -o tmp/test_32

# Run test with middle buffer
gcc ${FLAGS} -D BUFFER_SIZE=128 -I .. ../get_next_line.c ../get_next_line_utils.c test.c -o tmp/test_128

# Run test with fat buffer
gcc ${FLAGS} -D BUFFER_SIZE=10000000 -I .. ../get_next_line.c ../get_next_line_utils.c test.c -o tmp/test_10000000


#################  Show test result ##################


RED='\033[0;31m'
NC='\033[0m' # No Color


# ./test_1 stdin
printf "${RED}Test with buffer 1${NC}\n"
./tmp/test_1 > tmp/log_1
printf "${RED}Test with buffer 32${NC}\n"
./tmp/test_32 > tmp/log_32
printf "${RED}Test with buffer 128${NC}\n"
./tmp/test_128 > tmp/log_128
printf "${RED}Test with buffer 10000000${NC}\n"
./tmp/test_10000000 > tmp/log_10000000

printf "${RED}Diff with buffer 1${NC}\n"
diff -U 3 tmp/log_1 log_ref | cat -e
printf "${RED}Diff with buffer 32${NC}\n"
diff -U 3 tmp/log_1 tmp/log_32 | cat -e
printf "${RED}Diff with buffer 128${NC}\n"
diff -U 3 tmp/log_1 tmp/log_128 | cat -e
printf "${RED}Diff with buffer 10000000${NC}\n"
diff -U 3 tmp/log_1 tmp/log_10000000 | cat -e

