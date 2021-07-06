#include "DXUT.h"
#include "DialogScene.h"

void DialogScene::Init()
{
	dialog = new Dialog();
	char str[256];
	sprintf(str, "stage%d", type);
	dialog->go_scene = str;
	switch (type)
	{
	case 1:
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("여기는 관제센터, 대위님 들리십니까!!"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("으윽.. 젠장 폭발 때문에 아무것도 기억이 안나는군", "여기는 볼트 N1-3기체, 들린다"));
		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("방금 폭발사고로 인해 부분적으로 기억을 잃은 것 같아"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("괜찮으십니까? 몸은 안다치셨습니까?"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("작은 상처 말고는 괜찮아", "지금 상황 좀 짧게 설명해줄 수 있나?"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("네 알겠습니다", "저는 공군특수대대 볼트 소속 관제센터 요원 리나입니다"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("현재 저희 임무는 도시의 전기를 모두 훔쳐간", "'트릭스터즈' 의 본거지를 추적하는 것입니다"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("고맙군 리나, 혹시 새 기체를 지원해줄 수 있나?", "방금 잿더미가 되서 말이야"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("네, 바로 보내드리겠습니다"));
		break;
	case 2:
		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("리나, 여기 상황 정리했어"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("수고하셨습니다, 제가 더 조사를 해봤는데,", "'트릭스터즈' 는 단순 테러조직이 아닌", "사이비종교인 것 같습니다"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("조직 보스인 트릭스터는 재벌집 아들이었고,", "그의 이름으로 2068년에 탈세 및 상습사기", "전과도 있습니다"));
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("펼치고 있던 사업도 망하고, 그로인해 늘 형과 비교를 당해", "망상증이 생겨 이런 짓을 벌인 것으로 보입니다"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("그렇군 모든 일에는 이유가 있는 법이지"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("방금 '트릭스터즈' 의 본거지를 알아냈습니다", "그리로 워프시켜드리겠습니다", "행운을 빕니다"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("고맙네"));
		break;
	case 3:
		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("역시 본거지라 그런지 보안이 철통이군"));

		dialog->chat_types.emplace_back(ChatType::TRICKSTER2ME);
		dialog->scripts.emplace_back(Script("왜.. 왜이러는거야!! 난 그저 벗어나고 싶은거라고!", "신께서 전기를 바치면 구원해주신댔어!! 내가 들었다고!"));

		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("완전히 돌았군", "트릭스터, 지금이라도 손들고 투항해라"));

		dialog->chat_types.emplace_back(ChatType::TRICKSTER2ME);
		dialog->scripts.emplace_back(Script("지금이라고 내가 포기할것같아?!"));

		dialog->chat_types.emplace_back(ChatType::ME2TRICKSTER);
		dialog->scripts.emplace_back(Script("좋아, 참교육 들어간다"));
		break;
	case 4:
		dialog->go_scene = "clear";

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("리나, 트릭스터 제압에 성공했다"));

		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->scripts.emplace_back(Script("수고하셨습니다 대위님"));

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->scripts.emplace_back(Script("그래 휴가나오면 밥이라도 사겠네", "그때 다시 만나지"));
		break;
	}

	//dialog->chater1.pos = V2(CENTER.x - 300, CENTER.y - 100);
	//dialog->chater2.pos = V2(CENTER.x + 300, CENTER.y - 100);

	OBJ->Add(dialog, "dialog")->pos = CENTER;
}

void DialogScene::Update()
{
}

void DialogScene::Render()
{
}

void DialogScene::Release()
{
}
