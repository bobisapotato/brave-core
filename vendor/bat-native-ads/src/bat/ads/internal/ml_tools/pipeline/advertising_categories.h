/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_ADVERTISING_CATEGORIES_H_  // NOLINT
#define BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_ADVERTISING_CATEGORIES_H_  // NOLINT

#include <map>
#include <string>

namespace ads {
namespace ml_tools {
namespace pipeline {

std::map<std::string, int> get_advertising_categories() {
  std::map<std::string, int> advertising_categories = {};
  advertising_categories["architecture-architecture"] = 0;
  advertising_categories["arts & entertainment-animation"] = 1;
  advertising_categories["arts & entertainment-anime"] = 2;
  advertising_categories["arts & entertainment-arts & entertainment"] = 3;
  advertising_categories["arts & entertainment-celebrities"] = 4;
  advertising_categories["arts & entertainment-comics"] = 5;
  advertising_categories["arts & entertainment-design"] = 6;
  advertising_categories["arts & entertainment-film"] = 7;
  advertising_categories["arts & entertainment-humor"] = 8;
  advertising_categories["arts & entertainment-literature"] = 9;
  advertising_categories["arts & entertainment-music"] = 10;
  advertising_categories["arts & entertainment-opera"] = 11;
  advertising_categories["arts & entertainment-poetry"] = 12;
  advertising_categories["arts & entertainment-radio"] = 13;
  advertising_categories["arts & entertainment-television"] = 14;
  advertising_categories["arts & entertainment-theatre"] = 15;
  advertising_categories["arts & entertainment-video games"] = 16;
  advertising_categories["automotive-automotive"] = 17;
  advertising_categories["automotive-car brands"] = 18;
  advertising_categories["automotive-motorcycles"] = 19;
  advertising_categories["automotive-pickup trucks"] = 20;
  advertising_categories["business-advertising"] = 21;
  advertising_categories["business-biomedical"] = 22;
  advertising_categories["business-biotech"] = 23;
  advertising_categories["business-business"] = 24;
  advertising_categories["business-commerce"] = 25;
  advertising_categories["business-construction"] = 26;
  advertising_categories["business-ecommerce"] = 27;
  advertising_categories["business-energy"] = 28;
  advertising_categories["business-human resources"] = 29;
  advertising_categories["business-logistics"] = 30;
  advertising_categories["business-manufacturing"] = 31;
  advertising_categories["business-marketing"] = 32;
  advertising_categories["business-shipping"] = 33;
  advertising_categories["careers-careers"] = 34;
  advertising_categories["cell phones-cell phones"] = 35;
  advertising_categories["drugs-drugs"] = 36;
  advertising_categories["education-academia"] = 37;
  advertising_categories["education-education"] = 38;
  advertising_categories["education-homeschooling"] = 39;
  advertising_categories["family & parenting-family & parenting"] = 40;
  advertising_categories["family & parenting-parenting"] = 41;
  advertising_categories["family & parenting-pregnancy"] = 42;
  advertising_categories["fashion-beauty"] = 43;
  advertising_categories["fashion-body art"] = 44;
  advertising_categories["fashion-clothing"] = 45;
  advertising_categories["fashion-fashion"] = 46;
  advertising_categories["fashion-jewelry"] = 47;
  advertising_categories["folklore-astrology"] = 48;
  advertising_categories["folklore-folklore"] = 49;
  advertising_categories["folklore-paranormal phenomena"] = 50;
  advertising_categories["food & drink-baking"] = 51;
  advertising_categories["food & drink-barbecues & grilling"] = 52;
  advertising_categories["food & drink-beer"] = 53;
  advertising_categories["food & drink-cheese"] = 54;
  advertising_categories["food & drink-cider"] = 55;
  advertising_categories["food & drink-cocktails"] = 56;
  advertising_categories["food & drink-coffee"] = 57;
  advertising_categories["food & drink-cooking"] = 58;
  advertising_categories["food & drink-dining out"] = 59;
  advertising_categories["food & drink-food & drink"] = 60;
  advertising_categories["food & drink-pasta"] = 61;
  advertising_categories["food & drink-tea"] = 62;
  advertising_categories["food & drink-vegan"] = 63;
  advertising_categories["food & drink-vegetarian"] = 64;
  advertising_categories["food & drink-wine"] = 65;
  advertising_categories["health & fitness-aids hiv"] = 66;
  advertising_categories["health & fitness-alternative medicine"] = 67;
  advertising_categories["health & fitness-anatomy"] = 68;
  advertising_categories["health & fitness-asthma"] = 69;
  advertising_categories["health & fitness-autism"] = 70;
  advertising_categories["health & fitness-cancer"] = 71;
  advertising_categories["health & fitness-cardiac"] = 72;
  advertising_categories["health & fitness-chronic pain"] = 73;
  advertising_categories["health & fitness-deafness"] = 74;
  advertising_categories["health & fitness-dental care"] = 75;
  advertising_categories["health & fitness-depression"] = 76;
  advertising_categories["health & fitness-dermatology"] = 77;
  advertising_categories["health & fitness-diabetes"] = 78;
  advertising_categories["health & fitness-dieting"] = 79;
  advertising_categories["health & fitness-epilepsy"] = 80;
  advertising_categories["health & fitness-exercise"] = 81;
  advertising_categories["health & fitness-health & fitness"] = 82;
  advertising_categories["health & fitness-nutrition"] = 83;
  advertising_categories["health & fitness-pediatrics"] = 84;
  advertising_categories["health & fitness-psychology & psychiatry"] = 85;
  advertising_categories["health & fitness-sex"] = 86;
  advertising_categories["health & fitness-stress"] = 87;
  advertising_categories["history-archaeology"] = 88;
  advertising_categories["history-history"] = 89;
  advertising_categories["hobbies & interests-antiques"] = 90;
  advertising_categories["hobbies & interests-arts & crafts"] = 91;
  advertising_categories["hobbies & interests-board games"] = 92;
  advertising_categories["hobbies & interests-coins"] = 93;
  advertising_categories["hobbies & interests-dance"] = 94;
  advertising_categories["hobbies & interests-gambling"] = 95;
  advertising_categories["hobbies & interests-genealogy"] = 96;
  advertising_categories["hobbies & interests-hobbies & interests"] = 97;
  advertising_categories["hobbies & interests-horse racing"] = 98;
  advertising_categories["hobbies & interests-needlework"] = 99;
  advertising_categories["hobbies & interests-photography"] = 100;
  advertising_categories["hobbies & interests-sci-fi"] = 101;
  advertising_categories["hobbies & interests-scouting"] = 102;
  advertising_categories["hobbies & interests-smoking"] = 103;
  advertising_categories["hobbies & interests-writing"] = 104;
  advertising_categories["home-appliances"] = 105;
  advertising_categories["home-garden"] = 106;
  advertising_categories["home-home"] = 107;
  advertising_categories["home-interior design"] = 108;
  advertising_categories["law-crime"] = 109;
  advertising_categories["law-immigration"] = 110;
  advertising_categories["law-law"] = 111;
  advertising_categories["military-military"] = 112;
  advertising_categories["personal finance-banking"] = 113;
  advertising_categories["personal finance-credit & debt & loans"] = 114;
  advertising_categories["personal finance-insurance"] = 115;
  advertising_categories["personal finance-investing"] = 116;
  advertising_categories["personal finance-personal finance"] = 117;
  advertising_categories["personal finance-retirement planning"] = 118;
  advertising_categories["personal finance-stocks"] = 119;
  advertising_categories["personal finance-tax"] = 120;
  advertising_categories["pets-aquariums"] = 121;
  advertising_categories["pets-birds"] = 122;
  advertising_categories["pets-cats"] = 123;
  advertising_categories["pets-dogs"] = 124;
  advertising_categories["pets-pets"] = 125;
  advertising_categories["politics-government"] = 126;
  advertising_categories["politics-politics"] = 127;
  advertising_categories["real estate-mortgages"] = 128;
  advertising_categories["real estate-real estate"] = 129;
  advertising_categories["religion-buddhism"] = 130;
  advertising_categories["religion-christianity"] = 131;
  advertising_categories["religion-hinduism"] = 132;
  advertising_categories["religion-islam"] = 133;
  advertising_categories["religion-judaism"] = 134;
  advertising_categories["religion-religion"] = 135;
  advertising_categories["science-astronomy"] = 136;
  advertising_categories["science-biology"] = 137;
  advertising_categories["science-botany"] = 138;
  advertising_categories["science-chemistry"] = 139;
  advertising_categories["science-economics"] = 140;
  advertising_categories["science-geography"] = 141;
  advertising_categories["science-geology"] = 142;
  advertising_categories["science-mathematics"] = 143;
  advertising_categories["science-mechanics"] = 144;
  advertising_categories["science-palaeontology"] = 145;
  advertising_categories["science-physics"] = 146;
  advertising_categories["science-science"] = 147;
  advertising_categories["society-anthropology"] = 148;
  advertising_categories["society-dating"] = 149;
  advertising_categories["society-gay life"] = 150;
  advertising_categories["society-marriage"] = 151;
  advertising_categories["society-social networking"] = 152;
  advertising_categories["society-society"] = 153;
  advertising_categories["society-sociology"] = 154;
  advertising_categories["sports-american football"] = 155;
  advertising_categories["sports-archery"] = 156;
  advertising_categories["sports-athletics"] = 157;
  advertising_categories["sports-baseball"] = 158;
  advertising_categories["sports-basketball"] = 159;
  advertising_categories["sports-bodybuilding"] = 160;
  advertising_categories["sports-bowling"] = 161;
  advertising_categories["sports-boxing"] = 162;
  advertising_categories["sports-climbing"] = 163;
  advertising_categories["sports-cricket"] = 164;
  advertising_categories["sports-cycling"] = 165;
  advertising_categories["sports-diving"] = 166;
  advertising_categories["sports-fishing"] = 167;
  advertising_categories["sports-golf"] = 168;
  advertising_categories["sports-gymnastics"] = 169;
  advertising_categories["sports-hockey"] = 170;
  advertising_categories["sports-hunting"] = 171;
  advertising_categories["sports-jogging"] = 172;
  advertising_categories["sports-martial arts"] = 173;
  advertising_categories["sports-olympics"] = 174;
  advertising_categories["sports-racing"] = 175;
  advertising_categories["sports-rugby"] = 176;
  advertising_categories["sports-sailing"] = 177;
  advertising_categories["sports-skateboarding"] = 178;
  advertising_categories["sports-skiing"] = 179;
  advertising_categories["sports-snowboarding"] = 180;
  advertising_categories["sports-soccer"] = 181;
  advertising_categories["sports-sports"] = 182;
  advertising_categories["sports-surfing"] = 183;
  advertising_categories["sports-swimming"] = 184;
  advertising_categories["sports-tennis"] = 185;
  advertising_categories["sports-volleyball"] = 186;
  advertising_categories["sports-wrestling"] = 187;
  advertising_categories["sports-yoga"] = 188;
  advertising_categories["technology & computing-apple"] = 189;
  advertising_categories["technology & computing-database"] = 190;
  advertising_categories["technology & computing-freeware"] = 191;
  advertising_categories["technology & computing-gaming"] = 192;
  advertising_categories["technology & computing-programming"] = 193;
  advertising_categories["technology & computing-software"] = 194;
  advertising_categories["technology & computing-technology & computing"] = 195;
  advertising_categories["technology & computing-unix"] = 196;
  advertising_categories["technology & computing-windows"] = 197;
  advertising_categories["travel-adventure travel"] = 198;
  advertising_categories["travel-air travel"] = 199;
  advertising_categories["travel-hotels"] = 200;
  advertising_categories["travel-travel"] = 201;
  advertising_categories["weather-weather"] = 202;
  advertising_categories["crypto-crypto"] = 203;

  return advertising_categories;
}

}  // namespace pipeline
}  // namespace ml_tools
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_ADVERTISING_CATEGORIES_H_  // NOLINT
