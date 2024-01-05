#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyTextWidget.generated.h"

UCLASS()
class SOLARSYSTEMTESTBS_API UMyTextWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextBlockWidget;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* m;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* v;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* d;


public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		void SetMessage(const FText& Message, const FText& Message1, const FText& Message2, const FText& Message3);

protected:
	virtual void NativeConstruct() override;
};
