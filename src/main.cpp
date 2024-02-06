#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;

class $modify(CoolPauseLayer,PauseLayer)
{
	void showSettings(CCObject* target) {
		auto scene = reinterpret_cast<CCNode*>(CCScene::get());
		auto options = OptionsLayer::create();
		options->setZOrder(11);
		options->removeChildByTag(8);
		options->setVisible(true);
		options->enterLayer();
		scene->addChild(options);
	}

    void customSetup() {
        PauseLayer::customSetup();

		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto button = CCMenuItemSpriteExtra::create(
			buttonSprite, nullptr, this,
			menu_selector(CoolPauseLayer::showSettings)
		);
		button->setPosition(533, 248);
		if(auto menu = this->getChildByID("right-button-menu")) {
			menu->addChild(button);
			menu->updateLayout();
			buttonSprite->setScale(0.8);
		}
	}
};