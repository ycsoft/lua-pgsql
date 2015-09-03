local rapidjson = require('rapidjson')
local pgsql = require('pgsql')
--local value = rapidjson.decode('{"age":20,"friends":["yang","chen"]}')
--print(getmetatable(value["friends"]).__jsontype)
local conn = pgsql.connectdb("hostaddr=127.0.0.1 dbname=fasp_yz user=postgres password=postgres")
local res = conn:exec("select getbydate('c016','2015-01-01','');")

print(res)

function outObject(Obj)
  for k,v in pairs(Obj) do
    local tp = getmetatable(v).__jsontype
    if (tp ~= "object" and tp ~= "array" ) then
      print(k,"=",v)
    else if(tp == "object") then
      outObject(V)
    else if (tp == "array") then
      --to process array
      print("Array")
    end
    end
    end
  end
end
