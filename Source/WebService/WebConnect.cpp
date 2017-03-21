#include "WebService.h"
#include "WebConnect.h"


UWebConnect::UWebConnect()
{
	UE_LOG(LogTemp, Warning,
		TEXT("UWebConnect Constructor Call !"));

	Host = TEXT("localhost:8000");
	URI = TEXT("/");
}

void UWebConnect::RequestToken()
{
	UE_LOG(LogClass, Warning, TEXT("Request Token Call!"));
}