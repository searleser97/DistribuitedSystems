	$(document).ready(function() {
		$("img.lazy").lazyload({effect: "fadeIn"});
		$.ajax({
			url: "/getHosts"
		}).done(function(data){
			var datos = jQuery.parseJSON(data);
			var hosts = datos["hosts"];
			for(var i = 0; i < hosts.length; ++i){
				$('.etabs').append('<li class="tab"><a href="#host_' + i + '">' + hosts[i] + '</a></li>');
				$('.panel-container').append('<div id="host_' + i + '"><div id="tabla_resultados_' + i + '" class="tabla_resultados"></div></div>');
				$.ajax({
					url: "/getCaptures?host=" + hosts[i],
					i: i
				}).done(function(data2){
					var datos2 = jQuery.parseJSON(data2);
					var files = datos2["captures"];
					for(var j = 0; j < files.length && j < 10; ++j){
						var fila = "<div class='resultado'><b>" + files[j] + "</b><br /><br /><img class='lazy' data-original='/" + hosts[this.i] + "/" + files[j] + "' width='600' height='600' /><br /></div>";
						$("#tabla_resultados_" + this.i).append(fila);
					}
					$("img.lazy").lazyload({effect: "fadeIn"});
				});
			}
			$('.tab-side-container').easytabs();

		});
	});