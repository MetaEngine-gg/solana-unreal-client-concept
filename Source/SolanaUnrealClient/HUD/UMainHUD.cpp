#include "UMainHUD.h"

void UMainHUD::RunCommand()
{
	FString Call = BaseApiText->GetText().ToString() + AddressText->GetText().ToString();
	OnRunCommand.Broadcast(Call);
}
