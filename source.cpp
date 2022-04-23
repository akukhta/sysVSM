#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstddef>

#define SIZE 2000000
#define MB   1000000

int main()
{
	key_t key = ftok("/tmp/mem.temp", 1);
	int shmID = shmget(key, SIZE, IPC_CREAT | 0666);

	unsigned char *data = static_cast<unsigned char*>(shmat(shmID, NULL, 0));

	for (size_t i = 0; i < MB; i++)
	{
		data[i] = 42;
	}

	shmdt(data);
}
