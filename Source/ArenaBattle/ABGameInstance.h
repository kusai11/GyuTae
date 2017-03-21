#pragma once
#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"


UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UABGameInstance();
	
	virtual void Init() override;

	UPROPERTY()
		class UWebConnect* WebConnect;

	UPROPERTY()
		class UWebConnect* WebConnect2;
};
