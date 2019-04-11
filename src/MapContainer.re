open Data;

module Map = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (
      ~center: array(float)=?,
      ~zoom: int,
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element
    ) =>
    React.element =
    "Map";
};

module TileLayer = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (~url: string, ~attribution: string, ~attributionUrl: string=?) =>
    React.element =
    "TileLayer";
};

module Marker = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~position: array(float)) => React.element = "Marker";
};

let style = ReactDOMRe.Style.make(~width="300px", ~height="300px", ());

let array_of_coordinates = ({lat, lng}) => [|lat, lng|];

[@react.component]
let make = (~city, _) =>
  <Map zoom=13 center={array_of_coordinates(city.coordinates)} style>
    <TileLayer
      url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
      attribution="&copy; <a href=&quot;http://osm.org/copyright&quot;>OpenStreetMap</a> contributors"
      attributionUrl=?{city.image.attributionUrl}
    />
    <Marker position={array_of_coordinates(city.coordinates)} />
  </Map>;
