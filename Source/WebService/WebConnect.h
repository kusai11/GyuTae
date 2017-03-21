#pragma once
#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"


UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	GENERATED_BODY()
	
public:
	UWebConnect();

	// Ŭ���� Ÿ���϶� �ݵ�� UPROPERTY() ��ũ�θ� ����.
	// UFUNCTION() ��ũ�θ� ����ϰ� �Ǹ� cpp���� delegate�� ����� �� �ִ�.

	UPROPERTY()
		FString Host;

	UPROPERTY()
		FString URI;

	UFUNCTION()
		void RequestToken();
};
