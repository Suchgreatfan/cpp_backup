.PHONY:clean test
CC=g++
CFLAGS=-Wall -g
BIN=query.exe
TEST=redis_test.exe
OBJS=main.o StringUtil.o TextQuery.o RedisClient.o
STAND= -std=c++0x
LINKS=-lmuduo_base -lpthread -lhiredis
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)
test:$(TEST)
$(TEST):RedisClient.o test_redis_client.o
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS) 
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(STAND)
clean:
	rm -f *.o $(BIN) $(TEST) core
