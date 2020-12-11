#include <ArduinoJson.h>

// generated from https://arduinojson.org/v6/assistant/
// JSON from https://github.com/CliffLin/TaipeiMRT/blob/master/flask/mrt.py
const char* json = "{\"stations\":[{\"id\":\"089\",\"line\":[\"板南線\",\"中和新蘆線\"],\"name\":\"忠孝新生\",\"english\":\"Zhongxiao Xinsheng\"},{\"id\":\"010\",\"line\":[\"板南線\",\"文湖線\"],\"name\":\"忠孝復興\",\"english\":\"Zhongxiao Fuxing\"},{\"id\":\"091\",\"line\":[\"板南線\"],\"name\":\"忠孝敦化\",\"english\":\"Zhongxiao Dunhua\"},{\"id\":\"092\",\"line\":[\"板南線\"],\"name\":\"國父紀念館\",\"english\":\"Sun Yat-Sen Memorial Hall\"},{\"id\":\"093\",\"line\":[\"板南線\"],\"name\":\"市政府\",\"english\":\"Taipei City Hall\"},{\"id\":\"094\",\"line\":[\"板南線\"],\"name\":\"永春\",\"english\":\"Yongchun\"},{\"id\":\"095\",\"line\":[\"板南線\"],\"name\":\"後山埤\",\"english\":\"Houshanpi\"},{\"id\":\"096\",\"line\":[\"板南線\"],\"name\":\"昆陽\",\"english\":\"Kunyang\"}]}";

DynamicJsonDocument doc(1536);
DeserializationError error = deserializeJson(doc, json);

JsonArray stations = doc["stations"];

JsonObject stations_0 = stations[0];
const char* stations_0_id = stations_0["id"]; // "089"

const char* stations_0_line_0 = stations_0["line"][0]; // "板南線"
const char* stations_0_line_1 = stations_0["line"][1]; // "中和新蘆線"

const char* stations_0_name = stations_0["name"]; // "忠孝新生"
const char* stations_0_english = stations_0["english"]; // "Zhongxiao Xinsheng"

JsonObject stations_1 = stations[1];
const char* stations_1_id = stations_1["id"]; // "010"

const char* stations_1_line_0 = stations_1["line"][0]; // "板南線"
const char* stations_1_line_1 = stations_1["line"][1]; // "文湖線"

const char* stations_1_name = stations_1["name"]; // "忠孝復興"
const char* stations_1_english = stations_1["english"]; // "Zhongxiao Fuxing"

JsonObject stations_2 = stations[2];
const char* stations_2_id = stations_2["id"]; // "091"

const char* stations_2_line_0 = stations_2["line"][0]; // "板南線"

const char* stations_2_name = stations_2["name"]; // "忠孝敦化"
const char* stations_2_english = stations_2["english"]; // "Zhongxiao Dunhua"

JsonObject stations_3 = stations[3];
const char* stations_3_id = stations_3["id"]; // "092"

const char* stations_3_line_0 = stations_3["line"][0]; // "板南線"

const char* stations_3_name = stations_3["name"]; // "國父紀念館"
const char* stations_3_english = stations_3["english"]; // "Sun Yat-Sen Memorial Hall"

JsonObject stations_4 = stations[4];
const char* stations_4_id = stations_4["id"]; // "093"

const char* stations_4_line_0 = stations_4["line"][0]; // "板南線"

const char* stations_4_name = stations_4["name"]; // "市政府"
const char* stations_4_english = stations_4["english"]; // "Taipei City Hall"

JsonObject stations_5 = stations[5];
const char* stations_5_id = stations_5["id"]; // "094"

const char* stations_5_line_0 = stations_5["line"][0]; // "板南線"

const char* stations_5_name = stations_5["name"]; // "永春"
const char* stations_5_english = stations_5["english"]; // "Yongchun"

JsonObject stations_6 = stations[6];
const char* stations_6_id = stations_6["id"]; // "095"

const char* stations_6_line_0 = stations_6["line"][0]; // "板南線"

const char* stations_6_name = stations_6["name"]; // "後山埤"
const char* stations_6_english = stations_6["english"]; // "Houshanpi"

JsonObject stations_7 = stations[7];
const char* stations_7_id = stations_7["id"]; // "096"

const char* stations_7_line_0 = stations_7["line"][0]; // "板南線"

const char* stations_7_name = stations_7["name"]; // "昆陽"
const char* stations_7_english = stations_7["english"]; // "Kunyang"
