open Data

module Map = {
  [@react.component]
  [@bs.module "react-leaflet"]
  external make : (~center: array(float)=?, ~style: ReactDOMRe.Style.t=?, ~children : 'a) => React.element = "Map";
};

module TileLayer = {
  [@react.component]
  [@bs.module "react-leaflet"]
  external make : (~url:string, ~attributionUrl: string=?) => React.element = "TileLayer";
};
module Marker = {
  [@react.component]
  [@bs.module "react-leaflet"]
  external make : (~position: array(float)) => React.element = "Marker";

let style = ReactDOMRe.Style.make(~width="300px", ~height="300px", ())

let array_of_record = ({lat, lng}) => [|lat, lng|];

[@react.component]
let make = (~city) => {
  let position = array_of_record(city.coordinates);
  <div> 
    <Map center=position style> 
      <TileLayer url=city.image.url attributionUrl=?city.image.attributionUrl /> 
      <Marker position />
    </Map> 
  </div>
}