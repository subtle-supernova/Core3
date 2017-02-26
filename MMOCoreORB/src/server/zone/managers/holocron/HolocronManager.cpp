/*
 * HolocronManager.cpp
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#include "HolocronManager.h"
#include "server/zone/ZoneClientSession.h"
#include "server/zone/ZoneServer.h"
//#include "server/zone/packets/ui/CreateTicketResponseMessage.h"
#include "server/zone/packets/ui/RequestCategoriesResponseMessage.h"
#include "server/login/account/AccountManager.h"
#include "BugCategory.h"

void HolocronManager::loadBugCategories() {
	return;

	Reference<ResultSet*> result = NULL;

}

void HolocronManager::sendRequestCategoriesResponseTo(ZoneClientSession* client) {
	RequestCategoriesResponseMessage* rcrm = new RequestCategoriesResponseMessage(&categories);
	client->sendMessage(rcrm);
}

void HolocronManager::submitTicket(ZoneClientSession* client, const UnicodeString& ticketBody) {
	return; 

	//TODO: Find out why this is causing a crash!
	//CreateTicketResponseMessage* ctrm = new CreateTicketResponseMessage();
	//client->sendMessage(ctrm);
}

uint32 HolocronManager::getReporterId(ZoneClientSession* client) {
    return;
}

uint32 HolocronManager::createReporterId(ZoneClientSession* client) {
	return 0;
}

String HolocronManager::getTokenValue(const String& token, const UnicodeString& report) {
	return;
}

uint32 HolocronManager::getSeverityFromString(const String& str) {
	return 20;
}
uint32 HolocronManager::getReproducibilityFromString(const String& str) {
	return 10;
}