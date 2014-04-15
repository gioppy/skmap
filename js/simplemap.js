(function($){
  Drupal.behaviors.simpleMap = {
    attach:function(context){
      var latLng = Drupal.settings.skmap.simple_map;
      var data = {
        "type":"FeatureCollection",
        "features":[{
          "type":"Feature",
          "geometry":{
            "type":"Point",
            "coordinates":[
              latLng.longitude,
              latLng.latitude
            ]
          },
        "properties":{
          "name":"",
          "description":""
        }}]
      };
      
      $('#skmap-simple-map').shakemap({
        data:data,
        mapOptions:Drupal.settings.skmap.map_options,
        action:null
      })
    }
  }
})(jQuery);