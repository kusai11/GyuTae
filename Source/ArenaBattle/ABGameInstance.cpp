#include "ArenaBattle.h"
#include "ABGameInstance.h"

#include "WebConnect.h"


// ���� �ʱ�ȭ���� �������
UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("%s"), TEXT("UABGameInstance Constructor !"));

	// ������ �ڵ忡���� ���Ǵ� �Լ�
	WebConnect = CreateDefaultSubobject<UWebConnect>(TEXT("WebConnect"));
}

// ���� ���������� �������
void UABGameInstance::Init()
{
	AB_LOG_CALLONLY(Warning);
	Super::Init();
	WebConnect2 = NewObject<UWebConnect>(this);

	UClass* ClassInfo1 = WebConnect->GetClass();
	UClass* ClassInfo2 = UWebConnect::StaticClass();

	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2"));
	}

	for (TFieldIterator<UProperty> It(ClassInfo1); It; ++It)
	{
		// Ŭ���� ���� ��� ������Ƽ�� ����Ѵ�.
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"),
			*It->GetName(), *It->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());

		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"),
				*StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}

	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());
		UFunction* Func1 = ClassInfo1->FindFunctionByName(FName(TEXT("RequestToken")));
		if (Func1->ParmsSize == 0)
		{
			WebConnect->ProcessEvent(Func1, NULL);
		}
	}
}