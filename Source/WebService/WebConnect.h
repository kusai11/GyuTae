#pragma once
#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"


UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	GENERATED_BODY()
	
public:
	UWebConnect();

	// 클래스 타입일때 반드시 UPROPERTY() 매크로를 쓴다.
	// UFUNCTION() 매크로를 사용하게 되면 cpp에서 delegate를 사용할 수 있다.

	UPROPERTY()
		FString Host;

	UPROPERTY()
		FString URI;

	UFUNCTION()
		void RequestToken();
};
