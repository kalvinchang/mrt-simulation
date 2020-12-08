#include <ArduinoJson.h>

// generated from https://arduinojson.org/v6/assistant/

const size_t capacity = 18*JSON_ARRAY_SIZE(1) + 4*JSON_ARRAY_SIZE(2) + JSON_ARRAY_SIZE(22) + JSON_OBJECT_SIZE(1) + 22*JSON_OBJECT_SIZE(3) + 350;
DynamicJsonDocument doc(capacity);

const char* json = "{\"stations\":[{\"id\":\"077\",\"line\":[\"板南線\"],\"name\":\"永寧\"},{\"id\":\"078\",\"line\":[\"板南線\"],\"name\":\"土城\"},{\"id\":\"079\",\"line\":[\"板南線\"],\"name\":\"海山\"},{\"id\":\"080\",\"line\":[\"板南線\"],\"name\":\"亞東醫院\"},{\"id\":\"081\",\"line\":[\"板南線\"],\"name\":\"府中\"},{\"id\":\"082\",\"line\":[\"板南線\"],\"name\":\"板橋\"},{\"id\":\"083\",\"line\":[\"板南線\"],\"name\":\"新埔\"},{\"id\":\"084\",\"line\":[\"板南線\"],\"name\":\"江子翠\"},{\"id\":\"085\",\"line\":[\"板南線\"],\"name\":\"龍山寺\"},{\"id\":\"086\",\"line\":[\"板南線\",\"松山新店線\"],\"name\":\"西門\"},{\"id\":\"051\",\"line\":[\"板南線\",\"淡水信義線\"],\"name\":\"台北車站\"},{\"id\":\"088\",\"line\":[\"板南線\"],\"name\":\"善導寺\"},{\"id\":\"089\",\"line\":[\"板南線\",\"中和新蘆線\"],\"name\":\"忠孝新生\"},{\"id\":\"010\",\"line\":[\"板南線\",\"文湖線\"],\"name\":\"忠孝復興\"},{\"id\":\"091\",\"line\":[\"板南線\"],\"name\":\"忠孝敦化\"},{\"id\":\"092\",\"line\":[\"板南線\"],\"name\":\"國父紀念館\"},{\"id\":\"093\",\"line\":[\"板南線\"],\"name\":\"市政府\"},{\"id\":\"094\",\"line\":[\"板南線\"],\"name\":\"永春\"},{\"id\":\"095\",\"line\":[\"板南線\"],\"name\":\"後山埤\"},{\"id\":\"096\",\"line\":[\"板南線\"],\"name\":\"昆陽\"},{\"id\":\"097\",\"line\":[\"板南線\"],\"name\":\"南港\"},{\"id\":\"031\",\"line\":[\"板南線\"],\"name\":\"南港展覽館\"}]}";

DeserializationError error = deserializeJson(doc, json);

JsonArray stations = doc["stations"];

JsonObject stations_0 = stations[0];
const char* stations_0_id = stations_0["id"]; // "077"

const char* stations_0_line_0 = stations_0["line"][0]; // "板南線"

const char* stations_0_name = stations_0["name"]; // "永寧"

JsonObject stations_1 = stations[1];
const char* stations_1_id = stations_1["id"]; // "078"

const char* stations_1_line_0 = stations_1["line"][0]; // "板南線"

const char* stations_1_name = stations_1["name"]; // "土城"

JsonObject stations_2 = stations[2];
const char* stations_2_id = stations_2["id"]; // "079"

const char* stations_2_line_0 = stations_2["line"][0]; // "板南線"

const char* stations_2_name = stations_2["name"]; // "海山"

JsonObject stations_3 = stations[3];
const char* stations_3_id = stations_3["id"]; // "080"

const char* stations_3_line_0 = stations_3["line"][0]; // "板南線"

const char* stations_3_name = stations_3["name"]; // "亞東醫院"

JsonObject stations_4 = stations[4];
const char* stations_4_id = stations_4["id"]; // "081"

const char* stations_4_line_0 = stations_4["line"][0]; // "板南線"

const char* stations_4_name = stations_4["name"]; // "府中"

JsonObject stations_5 = stations[5];
const char* stations_5_id = stations_5["id"]; // "082"

const char* stations_5_line_0 = stations_5["line"][0]; // "板南線"

const char* stations_5_name = stations_5["name"]; // "板橋"

JsonObject stations_6 = stations[6];
const char* stations_6_id = stations_6["id"]; // "083"

const char* stations_6_line_0 = stations_6["line"][0]; // "板南線"

const char* stations_6_name = stations_6["name"]; // "新埔"

JsonObject stations_7 = stations[7];
const char* stations_7_id = stations_7["id"]; // "084"

const char* stations_7_line_0 = stations_7["line"][0]; // "板南線"

const char* stations_7_name = stations_7["name"]; // "江子翠"

JsonObject stations_8 = stations[8];
const char* stations_8_id = stations_8["id"]; // "085"

const char* stations_8_line_0 = stations_8["line"][0]; // "板南線"

const char* stations_8_name = stations_8["name"]; // "龍山寺"

JsonObject stations_9 = stations[9];
const char* stations_9_id = stations_9["id"]; // "086"

const char* stations_9_line_0 = stations_9["line"][0]; // "板南線"
const char* stations_9_line_1 = stations_9["line"][1]; // "松山新店線"

const char* stations_9_name = stations_9["name"]; // "西門"

JsonObject stations_10 = stations[10];
const char* stations_10_id = stations_10["id"]; // "051"

const char* stations_10_line_0 = stations_10["line"][0]; // "板南線"
const char* stations_10_line_1 = stations_10["line"][1]; // "淡水信義線"

const char* stations_10_name = stations_10["name"]; // "台北車站"

JsonObject stations_11 = stations[11];
const char* stations_11_id = stations_11["id"]; // "088"

const char* stations_11_line_0 = stations_11["line"][0]; // "板南線"

const char* stations_11_name = stations_11["name"]; // "善導寺"

JsonObject stations_12 = stations[12];
const char* stations_12_id = stations_12["id"]; // "089"

const char* stations_12_line_0 = stations_12["line"][0]; // "板南線"
const char* stations_12_line_1 = stations_12["line"][1]; // "中和新蘆線"

const char* stations_12_name = stations_12["name"]; // "忠孝新生"

JsonObject stations_13 = stations[13];
const char* stations_13_id = stations_13["id"]; // "010"

const char* stations_13_line_0 = stations_13["line"][0]; // "板南線"
const char* stations_13_line_1 = stations_13["line"][1]; // "文湖線"

const char* stations_13_name = stations_13["name"]; // "忠孝復興"

JsonObject stations_14 = stations[14];
const char* stations_14_id = stations_14["id"]; // "091"

const char* stations_14_line_0 = stations_14["line"][0]; // "板南線"

const char* stations_14_name = stations_14["name"]; // "忠孝敦化"

JsonObject stations_15 = stations[15];
const char* stations_15_id = stations_15["id"]; // "092"

const char* stations_15_line_0 = stations_15["line"][0]; // "板南線"

const char* stations_15_name = stations_15["name"]; // "國父紀念館"

JsonObject stations_16 = stations[16];
const char* stations_16_id = stations_16["id"]; // "093"

const char* stations_16_line_0 = stations_16["line"][0]; // "板南線"

const char* stations_16_name = stations_16["name"]; // "市政府"

JsonObject stations_17 = stations[17];
const char* stations_17_id = stations_17["id"]; // "094"

const char* stations_17_line_0 = stations_17["line"][0]; // "板南線"

const char* stations_17_name = stations_17["name"]; // "永春"

JsonObject stations_18 = stations[18];
const char* stations_18_id = stations_18["id"]; // "095"

const char* stations_18_line_0 = stations_18["line"][0]; // "板南線"

const char* stations_18_name = stations_18["name"]; // "後山埤"

JsonObject stations_19 = stations[19];
const char* stations_19_id = stations_19["id"]; // "096"

const char* stations_19_line_0 = stations_19["line"][0]; // "板南線"

const char* stations_19_name = stations_19["name"]; // "昆陽"

JsonObject stations_20 = stations[20];
const char* stations_20_id = stations_20["id"]; // "097"

const char* stations_20_line_0 = stations_20["line"][0]; // "板南線"

const char* stations_20_name = stations_20["name"]; // "南港"

JsonObject stations_21 = stations[21];
const char* stations_21_id = stations_21["id"]; // "031"

const char* stations_21_line_0 = stations_21["line"][0]; // "板南線"

const char* stations_21_name = stations_21["name"]; // "南港展覽館"
